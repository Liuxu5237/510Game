#!/bin/bash

Cur_Dir=$(pwd)
GAMELIST_DIR="game_list.txt"
BASE_DIR=$Cur_Dir/../client/ciphercode/base
CLIENT_DIR=$Cur_Dir/../client/ciphercode/client

function games_md5(){
	i=0
for line in  `cat $GAMELIST_DIR`
do
	#跳过第一行
	i=`expr $i + 1`
	if [ $i == 1 ] 
	then 
		continue 
	fi
	
	name1=`echo $line | cut -d \, -f 1`
	name2=`echo $name1 | cut -d \= -f 2`
	echo "    Build game md5 -> "$name2

	des1=`echo $line | cut -d \, -f 2`
	des2=`echo $des1 | cut -d \= -f 2`
	des=$Cur_Dir/../$des2
	
	./MakeFilemd5List -d $des
done
}

./MakeFilemd5List -d $BASE_DIR
./MakeFilemd5List -d $CLIENT_DIR
games_md5
