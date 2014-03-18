######################################################################################
#	
#	file:	docker_install.sh
#	author: hahaya
#	email:	hahayacoder@gmail.com
#	date:	2014-3-16
#	version:v0.1
#	useage:	chmod 0777 docker_install.sh
#		./docker_install.sh
#       note:   install docker
#
#######################################################################################
#! /bin/bash

#安装docker
docker_version=`sudo docker version`
if [ -z "$docker_version" ]; then
    sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 36A1D7869245C8950F966E92D8576A8BA88D21E9
    sudo sh -c "echo deb http://get.docker.io/ubuntu docker main > /etc/apt/sources.list.d/docker.list"
    sudo apt-get update
    sudo apt-get install -y lxc-docker
    sudo docker pull busybox
    sudo docker run busybox echo "hello world"
else
    echo "docker has already install."
fi

#制作docker镜像
read -p "Do you want to make ubuntu13.04 image?[Y/N]"
if [ "$REPLY" = "Y" -o "$REPLY" = "y" ]; then
    user_name=`whoami`
    sudo apt-get install debootstrap
    sudo debootstrap raring ubuntu13.04 http://mirrors.163.com/ubuntu
    sudo chown -R "$user_name" ubuntu13.04
    image_name=${user_name}"/ubuntu13.04"
    tar -C ubuntu13.04/ -c . | sudo docker import - "$image_name"
    sudo docker run hahaya/ubuntu13.04 echo "hello world"
	
    echo "make image success."
fi

