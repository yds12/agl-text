sudo mkdir /usr/include/agl/text
sudo cp -Rap *.h /usr/include/agl/text/
make release
sudo cp -Rap ../lib/*.so /usr/lib/
