# War3 Inventory Hotkey Remapper

A simple Windows application that remaps keyboard keys to numpad keys for Warcraft 3 inventory management, perfect for laptops without dedicated numpads.

## Default Key Mappings

Based on the 6-slot inventory layout:

| Physical Key | Maps to | Inventory Slot |
|--------------|---------|----------------|
| 1            | Numpad 7| Top-left (Slot 1) |
| 2            | Numpad 8| Top-right (Slot 2) |
| 3            | Numpad 4| Middle-left (Slot 3) |
| 4            | Numpad 5| Middle-right (Slot 4) |
| Tab          | Numpad 1| Bottom-left (Slot 5) |
| Space        | Numpad 2| Bottom-right (Slot 6) |

## Quick Start

### Option 1: Use Pre-compiled Version
1. Download `war3hotkeys.exe`
2. Run as Administrator (required for global hotkeys)
3. The program runs in background - check console for "Enabled/Disabled" status
4. Press END key to toggle on/off
You can close the command prompt window whenever you're done using the tool.

### Option 2: Compile from Source

**Requirements:**
- Visual Studio 2022 with C++ Desktop Development workload
- Windows SDK

**Compilation:**
```bash
# Open Developer Command Prompt or VS Code terminal
cl /EHsc war3hotkeys.cpp user32.lib
```

## Customizing Hotkeys

To modify the key mappings, edit the `keyMap` in `war3hotkeys.cpp`:

```cpp
std::unordered_map<int, int> keyMap = {
    {'1', VK_NUMPAD7},     // Change VK_NUMPAD7 to your desired key
    {'2', VK_NUMPAD8},     // Change VK_NUMPAD8 to your desired key
    {'3', VK_NUMPAD4},     // etc.
    {'4', VK_NUMPAD5},
    {VK_TAB, VK_NUMPAD1},
    {VK_SPACE, VK_NUMPAD2}
};
```

### Common Virtual Key Codes:
- `VK_NUMPAD0` through `VK_NUMPAD9` - Numpad keys
- `'A'` through `'Z'` - Letter keys
- `'0'` through `'9'` - Number keys
- `VK_SPACE` - Spacebar
- `VK_TAB` - Tab key
- `VK_SHIFT` - Shift key
- `VK_CONTROL` - Ctrl key
- `VK_F1` through `VK_F12` - Function keys

[Full list of Virtual Key Codes](https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes)

## Usage Notes

- **Run as Administrator** - Required for global keyboard hooks
- **Toggle with END key** - Press END to enable/disable the remapper
- **Background operation** - Runs minimized, check console for status
- **Game compatibility** - Tested with Warcraft 3, should work with other games

## Troubleshooting

**"Access Denied" or hooks not working:**
- Right-click the executable and "Run as Administrator"

**Keys not remapping:**
- Check if the program shows "Enabled" in console
- Press END key to toggle if needed
- Ensure the target application has focus

**Compilation errors:**
- Make sure you have Visual Studio with C++ Desktop Development
- Use Developer Command Prompt
- Include `user32.lib` in compilation

## Contributing

Feel free to submit issues, fork the repository, and create pull requests for any improvements.

## License

This project is for **personal use only**. You are free to:
- Use the software for personal gaming
- Modify the code for your own use
- Share the source code with others

**Commercial use is prohibited** - this software may not be used for commercial purposes, sold, or included in commercial products without permission.
