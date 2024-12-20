#!/bin/bash

# Check if a commit message is provided
if [ -z "$1" ]; then
    echo "Usage: ./gitpush.sh \"Your commit message\""
    exit 1
fi

# Initialize Git repository if not already done
if [ ! -d ".git" ]; then
    git init
    echo "> Initialized a new Git repository."
fi

# Add all changes
git add .

# Commit with the provided message
git commit -m "$1"

# Add the remote repository if not already set
if ! git remote | grep -q origin; then
    git remote add origin https://github.com/sbidwaibing/Tree_DS_Practice.git
    echo "> Added remote repository: https://github.com/sbidwaibing/Tree_DS_Practice.git"
fi

# Push to the main branch
git push -u origin main

# Success message
echo "> Pushed successfully to Tree_DS_Practice"
