# Pico SDK Fix TODO

## Steps from Approved Plan:

- [x] Step 1: Edit `CMakeLists.txt` to add `set(PICO_SDK_FETCH_FROM_GIT ON)` before `include(pico_sdk_import.cmake)`.
- [ ] Step 2: Run build: `cd pico && mkdir -p build && cd build && cmake .. && make` (downloads SDK automatically).
- [ ] Step 3: Verify compilation succeeds (no 'pico/stdlib.h' error).
- [ ] Step 4: Optional: Flash to Pico (`make load` if connected).

**Notes**:
- ARM toolchain needed: `brew install arm-none-eabi-gcc` if missing.
- First build downloads ~100MB SDK.
