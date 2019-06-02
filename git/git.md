---
titlt:git 操作说明
---

# git 操作说明

+ 查看远程分支
~~~ shell
$ git branch -a
~~~

+ 查看本地分支
~~~ shell
$ git branch
~~~

+ 创建分支
~~~ shell
$ git branch test
$ git branch
~~~

+ 切换分支到test
~~~ shell
$ git branch
$ git checkout test
~~~

+ 删除本地分支   
~~~ shell
$ git branch -d xxxxx
//删除远程分支
$ git branch -r -d origin/branch-name
$ git push origin :branch-name
~~~

+ 查看本地和远程分支 
~~~ shell 
-a。前面带*号的代表你当前工作目录所处的分支
~~~

+ 提交pr
~~~ shell
$ git push origin 本地仓库:名称

$ git submodule update --init
~~~

+ 移除本地commit
~~~ shell
$ git reset HEAD~ 
~~~ 

+ 存储修改
~~~ shell
$ git stash
$ git stash list 查看列表
$ git stash clear 清空
~~~