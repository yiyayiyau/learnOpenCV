        echo "# OpenCV-Tutorial" >> README.md
        git init
        git add README.md
        git commit -m "first commit"//添加描述
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
        git branch -a
        //查看本地分支
        git branch
        //切换分支到 xxx
        git checkout xxx
        //删除本地分支   
        git branch -d xxxxx



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