#!/bin/sh

if [ $1 ]; then
    curl -I --silent $1 2>&1 | grep "Location" | cut -c 11-
fi