mv ../office1-1_7-package/office1-1/color/*.r2d2 .
for f in *.r2d2; do unzip $f -d ./$f.result; done;
python ./gettxt.py
