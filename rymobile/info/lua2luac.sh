# 加密出错提示
function CipherSrcError() {
echo $1
read -n 1
exit
}

# 压缩文件
function ZipFile() {
echo "*********************文件zip*********************"
Cur_Dir=$(pwd)

# 复制资源文件
cp -Rf $Cur_Dir/../client/game $Cur_Dir/../client_publish
cp -Rf $Cur_Dir/../client/client $Cur_Dir/../client_publish
cp -Rf $Cur_Dir/../client/base $Cur_Dir/../client_publish

# 删除所有.lua文件
find $Cur_Dir/../client_publish -type f -name '*.lua' -delete

#    # 删除旧的zip文件
#rm $Cur_Dir/../res/game.zip
#rm $Cur_Dir/../client_publish/base/res/client.zip
#
# 压缩文件
pushd $Cur_Dir/../client_publish
#zip -r $Cur_Dir/../client_publish/base/res/game.zip game
#if [ $? -eq 1 ]
#then
#CipherSrcError "压缩game出错"
#fi

zip -r $Cur_Dir/../client_publish/base/res/client.zip client
if [ $? -eq 1 ]
then
CipherSrcError "压缩client出错"
fi

if [ $? -eq 0 ]
then
#    Compile
CipherSrcError "Complete"
fi
}

# 主体代码
echo "*********************lua文件加密*********************"
Cur_Dir=$(pwd)
rm -rf $Cur_Dir/../client_publish/client
rm -rf $Cur_Dir/../client_publish/game
rm -rf $Cur_Dir/../client_publish/base
rm -rf $Cur_Dir/../client_publish/command

cocos luacompile -s $Cur_Dir/../client/client -d $Cur_Dir/../client_publish/client -e -k c5l0qU0aIZRBLfI2pKf -b R3HkX82TtxvEK0 --disable-compile
if [ $? -eq 1 ]
then
CipherSrcError "lua文件加密出错"
fi

cocos luacompile -s $Cur_Dir/../client/game -d $Cur_Dir/../client_publish/game -e -k c5l0qU0aIZRBLfI2pKf -b R3HkX82TtxvEK0 --disable-compile
if [ $? -eq 1 ]
then
CipherSrcError "lua文件加密出错"
fi

cocos luacompile -s $Cur_Dir/../client/base -d $Cur_Dir/../client_publish/base -e -k c5l0qU0aIZRBLfI2pKf -b R3HkX82TtxvEK0 --disable-compile
if [ $? -eq 1 ]
then
CipherSrcError "lua文件加密出错"
fi

cocos luacompile -s $Cur_Dir/../client/command -d $Cur_Dir/../client_publish/command -e -k c5l0qU0aIZRBLfI2pKf -b R3HkX82TtxvEK0 --disable-compile
if [ $? -eq 1 ]
then
CipherSrcError "lua文件加密出错"
fi

if [ $? -eq 0 ]
then
ZipFile
fi

read -n 1
exit