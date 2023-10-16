0x18-dynamic_libraries

gcc *.c -c -fPIC
gcc *.o -shared -o libdynamic.so
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
echo . | sudo tee -a /etc/ld.so.conf
sudo ldconfig

gcc main.c -L. -ldynamic -o a
