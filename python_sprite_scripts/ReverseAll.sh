for i in $(ls *.png) ; do py ReversePic.py $i ; mv $i ./png ; done
