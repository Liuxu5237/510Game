#!/bin/bash

Cur_Dir=$(pwd)
CIPHERCODE_DIR=$Cur_Dir/../client/ciphercode
GAMELIST_TXT="game_list.txt"

# 加密出错提示
function CipherSrcError() {
echo $1
read -n 1
exit
}


# 压缩文件
function ZipFile() {

pushd $CIPHERCODE_DIR

echo "zip client .."
zip -q -r $CIPHERCODE_DIR/base/res/client.zip client

if [ $? -eq 1 ]
then
CipherSrcError "压缩client出错"
fi

}

# 主体代码
echo "*********************lua文件加密*********************"

rm -rf $CIPHERCODE_DIR/client
rm -rf $CIPHERCODE_DIR/game
rm -rf $CIPHERCODE_DIR/base
rm -rf $CIPHERCODE_DIR/command

echo "    -> client"
cocos luacompile -s $Cur_Dir/../client/client -d $CIPHERCODE_DIR/client -e -k c5l0qU0aIZRBLfI2pKf -b R3HkX82TtxvEK0 --disable-compile
if [ $? -eq 1 ]
then
CipherSrcError "lua文件加密出错"
fi

echo "    -> base"
cocos luacompile -s $Cur_Dir/../client/base -d $CIPHERCODE_DIR/base -e -k c5l0qU0aIZRBLfI2pKf -b R3HkX82TtxvEK0 --disable-compile
if [ $? -eq 1 ]
then
CipherSrcError "lua文件加密出错"
fi

echo "    -> command"
cocos luacompile -s $Cur_Dir/../client/command -d $CIPHERCODE_DIR/command -e -k c5l0qU0aIZRBLfI2pKf -b R3HkX82TtxvEK0 --disable-compile
if [ $? -eq 1 ]
then
CipherSrcError "lua文件加密出错"
fi

echo "*********************复制资源文件*********************"
# 复制资源文件
cp -Rf $Cur_Dir/../client/client $CIPHERCODE_DIR
cp -Rf $Cur_Dir/../client/base $CIPHERCODE_DIR
# 删除所有.lua文件
find $CIPHERCODE_DIR -type f -name '*.lua' -delete
echo ""

echo "*********************加密图片文件*********************"
# 加密图片文件
. ./encryptImage.sh
echo ""

echo "*********************生成文件的md5表*********************"
# 生成文件的md5表
. ./make_FileMD5List.sh
echo ""

echo "*********************压缩zip*********************"
# 压缩文件
if [ $? -eq 0 ]
then
ZipFile
fi

echo "*********************cocos compile android*********************"
pushd $Cur_Dir
cp -f ../frameworks/.cocos-project.json ../
cp -f ../frameworks/.project ../
pushd $Cur_Dir/..
cocos compile -p android --ap android-20 -m release -j 4
rm -f .cocos-project.json
rm -f .project


date=`date +%H:%M:%S`
echo "*********************完成(${date})*********************"
exit