#!/usr/bin/env bash
docker run -e keymap=jethro -e subproject=defaultsp -e keyboard=xd60 --rm -v $('pwd'):/qmk:rw edasque/qmk_firmware
