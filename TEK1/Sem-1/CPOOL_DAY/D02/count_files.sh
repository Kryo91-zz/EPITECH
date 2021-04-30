#!/bin/bash

find . -type f | grep -v "./.git*" | wc -l
