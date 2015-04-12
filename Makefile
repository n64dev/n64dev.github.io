CFLAGS = -lexpat

include Makefile.thumbslist
	
.INTERMEDIATE: thumbsfinder

.PHONY: all clean thumbdirs
all: thumbs thumbsfinder


clean:
	rm -Rfv i/l i/m i/t Makefile.thumbslist thumbsfinder

Makefile.thumbslist: thumbsfinder index.html
	./thumbsfinder < index.html > Makefile.thumbslist
	
.PRECIOUS: %.html
%.html:
	mkdir -p ${@D}
	touch "$@"
	
i/l/%.jpg: i/%.jpg i/l/index.html
	convert "$<" -resize 640x480 "$@"
	
i/l/%.png: i/%.png i/l/index.html
	convert "$<" -resize 640x480 "$@"
	
i/m/%.jpg: i/%.jpg i/m/index.html
	convert "$<" -resize 320x240 "$@"
	
i/m/%.png: i/%.png i/m/index.html
	convert "$<" -resize 320x240 "$@"
	
i/t/%.jpg: i/%.jpg i/t/index.html
	convert "$<" -resize 160x120 "$@"
	
i/t/%.png: i/%.png i/t/index.html
	convert "$<" -resize 160x120 "$@"