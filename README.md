# STM32创新开发工具链 —— CubeMX+VSCode+CMake+OpenOCD
## 一、背景
  Keil作为嵌入式开发的经典IDE，虽具有集成度高，支持芯片广泛，易于上手等优势，但在如今AI发展的大背景下已经显现出缺乏语法高亮及代码格式化，无法接入vibe coding，不便于git协作等缺点；此外，CLion虽是JetBrains IDE产品的优质代表，却需要许可证且嵌入式烧录调试支持不足。因此，作者基于CubeMX与VSCode这两款实用性强，例程广泛，具AI支持的软件，开发本新式嵌入式开发工具链（显然目前是针对STM32，之后将支持更广泛的各类嵌入式芯片）。
## 二、前置安装
- CubeMX（建议最新版，作者使用6.18.1）
- VSCode（需安装插件： **C/C++ Packs** **Cortex-Debug**）
- CMake（建议最新版，作者使用4.4.4）
- Ninja
- Arm GNU Toolchain（包含核心编译器arm-none-eabi-gcc，链接器等）
- OpenOCD（建议最新版，作者使用20260302-0.12.0）
  注意后面四个软件须**加入系统环境变量！**
- 任意一款你想开发的*STM32 + 调试器*
## 三、食用方法
### 1.CubeMX生成初始化代码 
  选择CMake工具链
### 2.VSCode编译+写代码
  拖入文件夹，选择Debug模式，将调用CMake Ninja arm-none-eabi-gcc完成代码编译（生成.obj并链接得到.elf二进制文件）
### 3.OpenOCD烧录+调试
