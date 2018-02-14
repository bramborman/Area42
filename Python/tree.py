from os import listdir
from os.path import basename, isdir, join
from sys import argv


def tree(dirs):
    dir_count = 0
    file_count = 0

    # Use nested method to prevent breaking
    # the intendation and be able to have shared counters
    def __tree(dirs, intendation, print_full_name=False):
        nonlocal dir_count
        nonlocal file_count

        for j in range(len(dirs)):
            try:
                dir = dirs[j]
                # Print full name for arguments passed by user - for absolute roots
                # End with space so we can write error message on the same line
                print(dir if print_full_name else basename(dir), end=' ')
                content = sorted(listdir(dir))
                
                for i in range(len(content)):
                    left = "└" if i == len(content) - 1 else "├"
                    print("\n", intendation, left, "──", sep="", end=' ')

                    if isdir(join(dir, content[i])):
                        dir_count += 1
                        __tree([join(dir, content[i])], intendation + ("│   " if i < len(content) - 1 else "    "))
                    else:
                        file_count += 1
                        print(basename(content[i]), end="")
                
            except FileNotFoundError:
                print("[error: directory not found]", end=' ')
            except PermissionError:
                print("[error: process doesn't have a permission to access this directory]", end=' ')
            except:
                print("[error: unknown]", end=' ')
            
            if len(dirs) > 1:
                print()
    
    __tree(["."] if dirs is None or len(dirs) == 0 else dirs , "", True)
    print("\n\n", dir_count, " directories, ", file_count, " files found", sep="")


if __name__ == "__main__":
    tree(argv[1:])
