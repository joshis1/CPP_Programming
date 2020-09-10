FROM debian:stretch-slim as base

RUN apt-get update && apt-get install -y --no-install-recommends \
    sudo \
    vim \
    nano \
    tree \
    git \
    locales \
    locales-all \
    ssh \
    python3 \
    less \
    net-tools \
    iputils-ping \
    gcc  \
    g++  \
    meson \
    ninja-build 

ENTRYPOINT ["/bin/bash", "-c"]

RUN mkdir -p /app

CMD ["cd /app && rm -vrf builddir && meson builddir && cd builddir && ninja docker_test && ./docker_test"]

STOPSIGNAL SIGTERM
