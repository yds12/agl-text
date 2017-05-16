sudo mkdir /usr/include/agl/text
sudo cp -Rap *.h /usr/include/agl/text/
make debug
sudo cp -Rap ../lib/*.so /usr/lib/
