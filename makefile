COM = g++
DIR = /home/hideonatc/Documents/my-cpp-code/
all:$(f)
	$(COM) $(f).cpp -o $(f)
	$(DIR)$(f)
github:
	git add *
	git commit -m --all
	git push origin master
	hideonatc
	20300130js