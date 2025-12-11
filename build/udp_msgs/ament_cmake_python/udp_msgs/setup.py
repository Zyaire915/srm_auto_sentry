from setuptools import find_packages
from setuptools import setup

setup(
    name='udp_msgs',
    version='0.0.5',
    packages=find_packages(
        include=('udp_msgs', 'udp_msgs.*')),
)
