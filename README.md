# STM32创新开发工具链 —— CubeMX+VSCode+CMake+OpenOCD
## 一、背景
　　Keil作为嵌入式开发的经典IDE，虽具有集成度高，支持芯片广泛，易于上手等优势，但在如今AI发展的大背景下已经显现出缺乏语法高亮及代码格式化，无法接入vibe coding，.mxproject专有格式不便于git协作等缺点；此外，CLion虽是JetBrains IDE产品的优质代表，却需要许可证且嵌入式烧录调试支持不足。因此，作者基于CubeMX与VSCode这两款实用性强，例程广泛，具AI支持的软件，开发了本新式嵌入式开发工具链（目前仅是适配STM32，之后将支持更广泛的各类嵌入式芯片）。
## 二、前置安装
- CubeMX（建议最新版，作者使用6.18.1）
- VSCode（需安装插件： **C/C++ Extension Packs**  **Cortex-Debug**）
- CMake（建议最新版，作者使用4.4.4）
- Ninja
- Arm GNU Toolchain（包含核心编译器arm-none-eabi-gcc，链接器arm-none-eabi-ld等）
- OpenOCD（建议最新版，作者使用20260302-0.12.0）
  
  注意后面四个软件均须**加入系统环境变量！**
- 任意一款你想开发的*STM32 + 调试器*
## 三、食用方法
### 1.CubeMX生成初始化代码 
　　引脚配置方法一样，只需在最后Generate Code前选择CMake工具链。
  
  <img width="1541" height="700" alt="屏幕截图 2026-10-21 140737" src="https://github.com/user-attachments/assets/f731ce39-15b7-4da1-81ee-4dc2c4787565" />
  
### 2.VSCode编译+写代码
　　直接拖入所生成文件夹（如下图） 或 VSCode主界面 - Open Folder
  
  <img width="282" height="208" alt="image" src="https://github.com/user-attachments/assets/596e262c-9a2e-4e02-aee2-1dddb68a0c00" />
  <img width="311" height="380" alt="屏幕截图 2026-10-21 143204" src="https://github.com/user-attachments/assets/3983d67d-37a1-4dfe-a4a7-c19e867b3891" />

　　打开命令面板（快捷键ctrl+shift+p) CMake:Select Configure Preset 选择Debug模式 
  
  <img width="738" height="380" alt="image" src="https://github.com/user-attachments/assets/f5cc0df5-2f13-4295-a1cd-9290e8533658" />
  
　　Build构建工程 - 将调用*CMake Ninja ARM-GNU-Toolchain*共同完成代码编译（分别生成 .obj 并链接得到 .elf 二进制文件） 
  
  <img width="67" height="26" alt="image" src="https://github.com/user-attachments/assets/4a63cb2e-7569-455a-9bb6-af041ac0fab8" />
  
　　前面配置均正确则应如下输出Build completed 及 exit code 0
  
  <img width="1072" height="300" alt="image" src="https://github.com/user-attachments/assets/3a4cc866-9f49-4774-a47a-3382e8edf93f" />
  
　　现在你已经完成了代码初始化及编译！
  
　　建议实行模块化编程 → 新建用户文件夹User - Src/Inc 即可编制需要的算法代码

  <img width="608" height="280" alt="image" src="https://github.com/user-attachments/assets/837648a8-2eec-4e94-a5ca-a9e407b7baf5" />

### 3.OpenOCD烧录+调试
　　**OpenOCD** （中文名开源片上调试器）提供了多元化跨平台的烧录调试选项，核心文件是 tasks.json launch.json openocd.cfg 三个配置文件（即本仓库所提供的 openocd.cfg 及 .vscode 文件夹，复制粘贴到工程文件夹即可）。
- tasks.json 指定任务名，任务应调用的执行器和执行文件
- launch.json 确定调试文件（即.elf） 调试起点
- openocd.cfg 确定调试器类型 芯片类型 调试速度指标

　　对于**Jlink**调试，其实不建议使用OpenOCD，详见本帖 [CSDN](https://blog.csdn.net/weixin_45467056/article/details/119886361) 推荐使用SEGGER官方的Ozone工具。
