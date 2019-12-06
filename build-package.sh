#!/bin/bash

mk-build-deps -i -r -t "apt-get -y" /tmp/package/Eigen3ToPython/debian/control
cd /package/Eigen3ToPython
debuild --no-tgz-check -i -I -b -us -uc
