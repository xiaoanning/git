xcode删除本地git代码管理
创建工程时如果勾选了create local Git，或者svn checkout出来的工程带git代码管理功能，如何删除呢

将工程退出，打开终端，执行下面语句：

cd 工程路径（直接将工程文件拖拽至此）

find . -type d -name “.git”|xargs rm -rf

这时候再打开工程文件，之前的”M”标志消失，则表明操作成功！









svn
svn ignore 的用法（忽略文件及目录）
若想创建了一个文件夹，并且把它加入版本控制，但忽略文件夹中的所有文件的内容：
$ svn mkdir spool
$ svn propset svn:ignore '*' spool
$ svn ci -m 'Adding "spool" and ignoring its contents.'
若想创建一个文件夹，但不加入版本控制，即忽略这个文件夹：
$ mkdir spool
$ svn propset svn:ignore 'spool' .
$ svn ci -m 'Ignoring a directory called "spool".'
若已经创建了文件夹，并加入了版本控制，现在想忽略这个文件夹，但要保持文件夹的内容：
$ svn export spool spool-tmp
$ svn rm spool
$ svn ci -m 'Removing inadvertently added directory "spool".'
$ mv spool-tmp spool
$ svn propset svn:ignore 'spool' .
$ svn ci -m 'Ignoring a directory called "spool".'

如果想在SVN提交时，忽略某个文件，也就是某个文件不提交，可以使用
svn propedit svn:ignore命令。
下面详细介绍一下使用步骤。
单纯的看svn官方文档和一些网上搜索的资料，有时候真的不如亲自试验的好。
svn propedit svn:ignore 目录名称。
注意，在使用这个SVN的属性编辑前，你得确保后面的“目录名称”是SVN版本控制的目录。
如果要忽略此目录下的文件，可以如下操作。
比如，想忽略/product目录下的test.PHP文件。前提是/product目录必须在svn版本控制下，而test.php文件不在svn版本控制。
svn st先看一下状态，会显示如下：
?     /product/test.php
我们需要将test.php文件加入忽略列表。
此时先设置SVN默认的编辑器
export SVN_EDITOR=vim
然后，使用svn propedit svn:ignore ,用法如下
svn propedit svn:ignore /product
此时会出现一个VIM的编辑窗口，表示需要将某个文件加入到忽略列表里
我们在编辑窗口中，写入
test.php
然后保存，并退出VIM编辑器。
这时候会有一个提示：属性 “svn:ignore” 于 “product” 被设为新值。
表示文件test.php的svn:ignore属性设置成功。
然后使用svn st查看，会显示：
M        product
我们需要提交，然后这个svn:ignore属性才会起作用
svn ci -m '忽略test.php文件'
这时候，无论你如何修改test.php文件，再使用svn st时，也不会出现修改提示符合M了。
