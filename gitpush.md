        echo "# OpenCV-Tutorial" >> README.md
        git init
        git add README.md
        git commit -m "first commit"//添加描述
        // git commit -a ...一次提交所有的变化文件列表
        //添加远程库，名 origin
        git remote add origin https://github.com/yiyayiyau/OpenCV-Tutorial.git
        //if remote exist:  git remote set-url origin https://github.com/yiyayiyau/OpenCV-Tutorial.git
        // or:    git remote rm origin
        git push -u origin master
        // 查看远程库和地址(只查看库名则不用加-v)
        git remote -v
        // 修改库名或地址，即删除旧的添加新的
        git remote rm origin
        git remote add origin https://...
        //查看远程分支
        git branch -a //所有分支，-r, 远程，-l,本地
        //查看本地分支
        git branch
        //切换分支到 xxx
        git checkout xxx
        //创建并切换
        git checkout -b xxxx
        //删除本地分支   
        git branch -d xxxxx
        //删除orighin下的远程分支br
        git push origin :br
        //推送当前分支到远程服务器
        git push origin
        //推送本地所有分支到origin服务器
        git push --all origin
        //将origin的代码下载到本地，不合并
        git fetch origin master
        //查看本地master与远程master的差别
        git log -p master...origin/master
        //合并
        git merge origin/master
        //将远程代码下载到本地作为一个分支，然后合并
        git fetch origin master:t-branch
        git diff t-branch
        git merge t-branch
        //将远程代码下载到本地，并自动合并
        git pull origin master
        //创建tag
        git tag -a 'tag_name_v0.0.1' -m 'comment message'
        //查询当前所有tag
        git tag
        //按匹配查询
        git tag -l 'v0.1*'
        //将当前特定tag推送到远程
        git push origin tag_name
        //将当前所有tag推送到远程
        git push origin --all tags
        //将某个分支合并到master
        git merge xxx
        //查看远程origin master 的信息
        git remote show origin
        // 强制更新本地文件
        git reset --hard origin/master
        git checkout -path/file

        1.打开git bash
        2.cd pathname
        3.git add filename
        4.git commit -m "with filename or sth"
        //已经设置好远程库 名为 github
        5.git push -u github master
        // 创建分支
        5'. git branch branchname
        5''.git push -u github branchname

        删除GitHub文件夹
        git rm -r --cached pathname //--cached 不删除本地文件夹
        git commit -m 'delete ...dir'
        git push -u github master
        恢复以前版本
        git checkout -- pathname // 用版本库中的版本替换工作区的版本

        从本地文件删除，之后可以从版本库中恢复
        rm pathname
        要是commit，版本库中也会删除。实质是对删除操作做了一次记录，
        然后生成一个新的版本号，在该版本下没有该文件。可以使用 
        git reset --hard commit_id //commit_id 是原版本的版本号
        来恢复


        //在 dev分支上
        git branch
        git add xxx
        git commit -m 'xxxx' 'dev'
        git push -u origin dev

        git checkout master
        git pull origin master
        git merge dev

        git status

        git push origin master
