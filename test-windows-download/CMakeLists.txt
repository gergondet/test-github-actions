cmake_minimum_required(VERSION 3.20)

project(WindowsDownload LANGUAGES CXX)
set(URL "https://cfhcable.dl.sourceforge.net/project/boost/boost-binaries/1.77.0/boost_1_77_0-msvc-14.2-64.exe")
set(DESTINATION "boot.exe")
set(EXPECTED_SHA256 8cf6bb866ff83922b19a7418e94bc1fce87cae0dea6077624e44de3c6e27505a)
file(DOWNLOAD "${URL}" "${DESTINATION}" EXPECTED_HASH SHA256=${EXPECTED_SHA256} SHOW_PROGRESS STATUS DOWNLOAD_STATUS)
