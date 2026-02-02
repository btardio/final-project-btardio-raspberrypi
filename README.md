

### Start a build container

docker run -it --network=host -v /var/run/docker.sock:/var/run/docker.sock -u bitbake -v ./:/repo classimg /bin/bash

### Rsync a OPKG

rsync -lrvcm --compare-dest=/home/btardio/final_project/repeatable5/assignment-10-btardio/buildroot/output/target/ ./buildroot/output/target/ ./first_opkg/

### Mount for making a opkg

mount -t squashfs -o loop ./rootfs.squashfs /mnt/squashfs/

### Make an opkg

Package: WeThreeKingsOS
Version: 1.1.1
Architecture: all
Maintainer: btardio@gmail.com
Description: Items for final project that didn't fit in boot sector image

opkg-build first_opkg/

### Added an example tftp directory

### Added the ipk file at https://btardiopublicbucket.s3.us-west-1.amazonaws.com/we-three-kings-os_1.1.1_aarch64.ipk
