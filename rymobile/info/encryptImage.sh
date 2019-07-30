#!/bin/bash

Cur_Dir=$(pwd)
GAMELIST_DIR="game_list.txt"
BASE_DIR=$Cur_Dir/../client/ciphercode/base
CLIENT_DIR=$Cur_Dir/../client/ciphercode/client

function encrypt_games_res(){
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
	echo "    Encrypt game res -> "$name2

	des1=`echo $line | cut -d \, -f 2`
	des2=`echo $des1 | cut -d \= -f 2`
	des=$Cur_Dir/../$des2
	
	./EncryptImage -d $des -k 0x12345678 -mode e
done
}

echo "    Encrypt base res"
./EncryptImage -d $BASE_DIR -k 0x12345678 -mode e
echo "    Encrypt client res"
./EncryptImage -d $CLIENT_DIR -k 0x12345678 -mode e
#echo "Encrypt games res"
encrypt_games_res