Install meson ninja first
sudo apt-get install meson ninja-build

meson  builddir
cd builddir
ninja docker_test


In order to build the docker image.
$docker build -t docker_test ./Docker
In order to run this docker - use the following command.
$docker run --name docker_app  -ti --mount type=bind,source="$(pwd)"/,target=/app docker_test:latest

In order to stop the app.

$docker stop docker_app

