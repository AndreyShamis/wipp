#!/bin/bash
ifconfig | grep HWaddr|awk '{print $1 " " $5}'
