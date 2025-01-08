# qt_cmake_boilerplate

Qt + CMake + Vcpkg 项目模板。

包含 I18N / 主题样式切换 / 安装包制作等。

## 编译

### vcpkg 设置

在 `.vscode/settings.json` 中添加（以 vcpkg 的实际安装目录填写）：

```json
"cmake.configureArgs": [
    "-DCMAKE_TOOLCHAIN_FILE=c:/vcpkg/scripts/buildsystems/vcpkg.cmake"
]
```
