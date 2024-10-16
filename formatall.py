# -*- coding:utf8 -*-
import sys
import os

# 在如下 List 增加想要忽略的目录名称，如果想要格式化忽略目录的某个子目录，指定绝对路径格式化即可
ignoreDIR = [".git", ".svn", ".cache", "build", "3rdpart"]


def linux_sh(cmd, needprint=True):
    if needprint:
        print(cmd)
    return os.system(cmd)


def getFileList(dir, Filelist):
    newDir = dir
    cpptailname = r".cpp"
    htailname = r".h"
    if os.path.isfile(dir):
        filename = dir
        if filename.endswith(cpptailname) or filename.endswith(htailname):
            Filelist.append(dir)
    elif os.path.isdir(dir):
        for s in os.listdir(dir):
            if s in ignoreDIR:
                print("ignore {0} dir".format(s))
                continue
            newDir = os.path.join(dir, s)
            getFileList(newDir, Filelist)
    return Filelist


def formatAllFile(libPath):
    fileList = []
    print("start format ", libPath)
    fileList = getFileList(libPath, fileList)
    for file in fileList:
        cmd = "clang-format -i {0}".format(file)
        linux_sh(cmd)


if __name__ == "__main__":
    selectDir = ""
    specialDir = ""
    if len(sys.argv) == 2:
        selectDir = sys.argv[1]
    else:
        print("Usage: python formater.py targetDir")
        exit(0)
    formatAllFile(selectDir)
