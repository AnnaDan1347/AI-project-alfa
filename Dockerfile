FROM ubuntu:18.04
RUN apt update -y
RUN apt install apache2 -y
RUN apt install g++ -y
RUN apt install libcgicc3 -y
RUN apt install libcgicc-dev -y
RUN apt install make -y

copy index.html /var/www/html/
copy conf/apache2.conf /etc/apache2/apache2.conf
copy conf/cgid.conf /etc/apache2/mods-enabled/
copy conf/cgid.load /etc/apache2/mods-enabled/
copy conf/cgi.load /etc/apache2/mods-enabled/
copy src/serverRequest.js /var/www/html/src/serverRequest.js
copy src/index.css /var/www/html/src/index.css

copy src/_normalize.css /var/www/html/src/_normalize.css
copy src/_zeroing.css /var/www/html/src/_zeroing.css
copy src/particles.js /var/www/html/src/particles.js
copy src/app.js /var/www/html/src/app.js 

copy src/index.css /var/www/html/src/index.css
copy src/chooseArrow.jpg /var/www/html/src/chooseArrow.jpg
copy src/facebook.jpg /var/www/html/src/facebook.jpg
copy src/font.jpg /var/www/html/src/font.jpg
copy src/github.jpg /var/www/html/src/github.jpg
copy src/Group 19.jpg /var/www/html/src/Group 19.jpg
copy src/Group 47.jpg /var/www/html/src/Group 47.jpg
copy src/Group 48.jpg /var/www/html/src/Group 48.jpg
copy src/Group 49.jpg /var/www/html/src/Group 49.jpg
copy src/logo.jpg /var/www/html/src/logo.jpg 
copy src/vk.jpg /var/www/html/src/vk.jpg
copy src/appimg.js /var/www/html/src/appimg.js
copy src/particlesimg.js /var/www/html/src/particlesimg.js
copy src/serverRequest.js /var/www/html/src/serverRequest.js
copy src/main.png /var/www/html/src/main.png
copy src/result.png /var/www/html/src/result.png



RUN mkdir /var/www/cgi-bin
copy Makefile /var/www/cgi-bin/
copy script.cpp /var/www/cgi-bin/
copy db.txt /var/www/cgi-bin/db.txt
WORKDIR /var/www/cgi-bin
RUN make
RUN chmod 755 script.cgi
RUN rm Makefile script.cpp
CMD apache2ctl -D FOREGROUND
