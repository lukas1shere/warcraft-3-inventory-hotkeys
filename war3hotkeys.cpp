/*
 * War3 Inventory Hotkey Remapper v1.1
 * Author: lukas1shere
 * Last modified: August 5, 2025
 * Description: Remaps keyboard keys to numpad for Warcraft 3 inventory management
 * Also works with custom maps like DotA, Troll & Elves, etc.
 */
#include <windows.h>
#include <unordered_map>
#include <iostream>

// Global variables
bool isEnabled = true;

// Map hotkeys to numpad key scan codes
std::unordered_map<int, int> keyMap = {
    {'1', VK_NUMPAD7},
    {'2', VK_NUMPAD8},
    {'3', VK_NUMPAD4},
    {'4', VK_NUMPAD5},
    {VK_TAB, VK_NUMPAD1},
    {VK_SPACE, VK_NUMPAD2}
};

void SimulateKey(int key, bool keyDown) {
    keybd_event(key, 
                MapVirtualKey(key, 0), 
                keyDown ? 0 : KEYEVENTF_KEYUP, 
                0);
}

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0) {
        KBDLLHOOKSTRUCT* pKbdStruct = (KBDLLHOOKSTRUCT*)lParam;
        
        // Check for END key to toggle
        if (pKbdStruct->vkCode == VK_END && wParam == WM_KEYDOWN) {
            isEnabled = !isEnabled;
            std::cout << (isEnabled ? "Enabled" : "Disabled") << std::endl;
            return 1;
        }

        // Only process if enabled
        if (isEnabled) {
            auto it = keyMap.find(pKbdStruct->vkCode);
            if (it != keyMap.end()) {
                bool isKeyDown = (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN);
                bool isKeyUp = (wParam == WM_KEYUP || wParam == WM_SYSKEYUP);

                if (isKeyDown || isKeyUp) {
                    SimulateKey(it->second, isKeyDown);
                    return 1;  // Block original key
                }
            }
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int main() {
    // Install the hook
    HHOOK hHook = SetWindowsHookEx(WH_KEYBOARD_LL, 
                                  KeyboardProc, 
                                  GetModuleHandle(NULL), 
                                  0);
    
    if (!hHook) {
        std::cout << "Hook failed!" << std::endl;
        return 1;
    }

    std::cout << "Running! Press END to toggle on/off\n";
    std::cout << "Mappings:\n";
    std::cout << "1 -> Numpad 7\n";
    std::cout << "2 -> Numpad 8\n";
    std::cout << "3 -> Numpad 4\n";
    std::cout << "4 -> Numpad 5\n";
    std::cout << "Tab -> Numpad 1\n";
    std::cout << "Space -> Numpad 2\n";

    // Message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(hHook);
    return 0;
}