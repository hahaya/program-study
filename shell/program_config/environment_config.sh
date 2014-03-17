######################################################################################
#	
#	file:	environment_config.sh
#	author: hahaya
#	email:	hahayacoder@gmail.com
#	date:	2014-3-14
#	version:v0.1
#	useage:	chmod 0777 environment_config.sh
#		./environment_config.sh
#       note:   close vim before execute environment_config.sh
#
#######################################################################################

#! /bin/bash

echo "--------------------Start Config Program Environment----------------------------"
echo "--------------------Start Config Program Environment----------------------------"
echo "--------------------Start Config Program Environment----------------------------"

system_info=`uname -s`
if [ "$system_info" = "Linux" ]; then
    echo "Linux System."
fi

#安装git ssh需要自己配置并上传到github
git_info=`git --version`
if [ -z "$git_info" ]; then
    sudo apt-get -y install git
    echo "git finishe install."
else
    echo "git already installed."
fi

#安装vim版本>=7.4 因为对版本有要求 所以不能使用which vim来判断
vim_info=`vim --version | grep "Vi IMproved 7.4"`
if [ -z "$vim_info" ]; then
    sudo apt-get -y remove vim
    sudo apt-get -y remove vim-runtime
    sudo apt-get -y remove gvim
    sudo apt-get -y remove vim-tiny
    sudo apt-get -y remove vim-common
    sudo apt-get -y remove vim-gui-common

    sudo add-apt-repository ppa:fcwu-tw/ppa
    sudo apt-get update
    sudo apt-get -y install vim
    
    echo "vim finish install."
else
    echo "vim already installed."
fi

#配置vim
user_name=`whoami`
vimrc_path="/home/"${user_name}"/.vimrc"
echo $vimrc_path
if [ -f "$vimrc_path" ]; then
    read -p ".vimrc already exist. Do you want to replace it?[Y/N]"
    if [ "$REPLY" = "Y" -o "$REPLY" = "y" ]; then
	cp ~/.vimrc ~/.vimrc_bak
	rm -rf ~/hahaya-vim
	git clone https://github.com/hahaya/hahaya-vim.git ~/hahaya-vim
	cd ~/hahaya-vim
	cp .vimrc ~/.vimrc
   
	echo "vim finish config."
    else
	echo "vim finish config."
    fi
else
    rm -rf ~/hahaya-vim
    git clone https://github.com/hahaya/hahaya-vim.git ~/hahaya-vim
    cd ~/hahaya-vim
    cp .vimrc ~/.vimrc
    
    echo "vim finish config."
fi

#安装gcc 因为对版本有要求 所以不能使用which gcc来判断 但是可以通过apt-cache show gcc查看软件的详细信息
gcc_info=`gcc --version | grep 4.8`
if [ -z "$gcc_info" ]; then
    sudo add-apt-repository ppa:ubuntu-toolchain-r/test
    sudo apt-get update
    sudo apt-get -y install gcc-4.8
    sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.8 50

    sudo apt-get -y install g++-4.8
    sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.8 50  

    echo "gcc finish install."
else
    echo "gcc already installed."
fi

#which build-essential得不到build-essential的信息
build_essential_info=`apt-cache show build-essential`
if [ -z "$build_essential_info" ]; then
    sudo apt-get -y install build-essential
    echo "build-essential finish install."
else
    echo "build-essential already installed."
fi

#tmux
tmux_info=`apt-cache show tmux`
if [ -z "$tmux_info" ]; then
    sudo apt-get -y install tmux
    echo "tmux finish install."
else
    echo "tmux already installed."
fi

#cmake
cmake_info=`cmake --version`
if [ -z "$cmake_info" ]; then
    sudo apt-get -y install cmake
    echo "cmake finish install."
else
    echo "cmake already installed."
fi

#ssh server
ssh_server_info=`apt-cache show openssh-server`
if [ -z "$ssh_server_info" ]; then
    sudo apt-get -y install openssh-server
    echo "openssh-server finish install."
else
    echo "openssh-server already installed."
fi

#ssh client
ssh_client_info=`apt-cache show openssh-client`
if [ -z "$ssh_client_info" ]; then
    sudo apt-get -y install openssh-client
    echo "openssh-client finish install."
else
    echo "openssh-client already installed."
fi

echo "--------------------Complete Config Program Environment-------------------------"
echo "--------------------Complete Config Program Environment-------------------------"
echo "--------------------Complete Config Program Environment-------------------------"
