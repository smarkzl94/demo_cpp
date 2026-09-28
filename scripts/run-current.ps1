param(
    [Parameter(Mandatory = $true)]
    [string]$Target
)

$Root = Split-Path -Parent $PSScriptRoot
$Exe = Join-Path $Root "build\bin\$Target.exe"

Set-Location $Root

# 1. 重新配置 CMake，确保新加的 .cpp 能被识别
#    如果文件没有变化，这一步几乎是秒过
cmake --preset mingw-debug
if (-not $?) {
    exit $LASTEXITCODE
}

# 2. 编译当前文件对应的目标
cmake --build --preset debug --target $Target
if (-not $?) {
    exit $LASTEXITCODE
}

# 3. 运行生成的可执行文件
& $Exe
exit $LASTEXITCODE
