######################################################################################
#	
#	file:	docker_depend.sh
#	author: hahaya
#	email:	hahayacoder@gmail.com
#	date:	2014-3-16
#	version:v0.1
#	useage:	chmod 0777 docker_depend.sh
#		./docker_depend.sh
#       note:   config the docker install environment
#
#######################################################################################
#! /bin/bash

#判断系统构架 docker目前只支持64位系统
machine_info=`uname -m`
if [ "$machine_info" = "x86_64" ]; then
    sudo apt-get update
    sudo apt-get install -y linux-image-generic-lts-raring 
    sudo apt-get install -y linux-headers-generic-lts-raring
    echo "install docker depend success."
    sudo reboot
else
    echo "docker should be installen on 64 bit system."
    exit
fid
