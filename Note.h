xcode删除本地git代码管理
创建工程时如果勾选了create local Git，或者svn checkout出来的工程带git代码管理功能，如何删除呢

将工程退出，打开终端，执行下面语句：

cd 工程路径（直接将工程文件拖拽至此）

find . -type d -name “.git”|xargs rm -rf

这时候再打开工程文件，之前的”M”标志消失，则表明操作成功！
