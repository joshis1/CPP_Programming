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

WORKDIR /root
COPY docker_test.cpp .
COPY meson.build .
RUN meson builddir && cd builddir && ninja docker_test 

FROM debian:stretch-slim
WORKDIR /root
COPY --from=base /root/builddir/docker_test .


ENTRYPOINT ["/bin/bash", "-c"]
CMD ["cd /root && ./docker_test"]







