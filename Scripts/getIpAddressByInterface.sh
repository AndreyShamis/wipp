#!/bin/bash
ifconfig $1 | grep 'inet addr:' | cut -d: -f2 | awk '{ print $1}' 
