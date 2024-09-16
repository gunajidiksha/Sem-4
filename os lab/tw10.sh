echo "Enter the current working directory name:"
read dir
    
# List directory contents and save to f2.txt
ls -l "$dir" > f2.txt

# Filter directories and count them
grep '^d' f2.txt > g1.txt
echo "The number of directories in the current working directory:"
wc -l g1.txt

# Filter files and count them
grep '^-' f2.txt > g1.txt
echo "The number of files in the current working directory:"
wc -l g1.txt

# Prompt for the name of the file
echo "Enter the name of the file:"
read file

# List the specified file details
ls -l "$file"

# Change file permissions and list details again
echo "The files after changing the permissions are:"
chmod u+x "$file"
ls -l "$file"
