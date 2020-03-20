        echo "# OpenCV-Tutorial" >> README.md
        git init
        git add README.md
        git commit -m "first commit"//添加描述
        //添加远程库
        git remote add origin https://github.com/yiyayiyau/OpenCV-Tutorial.git
        //if remote exist:  git remote set-url origin https://github.com/yiyayiyau/OpenCV-Tutorial.git
        // or:    git remote rm origin
        git push -u origin master


        1.打开git bash
        2.cd pathname
        3.git add filename
        4.git commit -m "with filename or sth"
        //已经设置好远程库 名为 github
        5.git push -u github master

        5'. git branch branchname
        5''.git push -u github branchname

        删除GitHub文件夹
        git rm -r --cached pathname //--cached 不删除本地文件夹
        git commit -m 'delete ...dir'
        git push -u github master

