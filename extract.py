import gzip
import os

def print_file(file_path, txt):
    dir = "C:\\Users\\[Your username here]\\Desktop\\mc_chat\\end_result" #this will create an end_result folder in mc_chat folder (if you dont want to have the mc_chat folder in Desktop you can change the path)
    os.makedirs(dir, exist_ok=True)
    with gzip.open(file_path, 'rt') as gzipped_file:
        dir_file = dir + '\\' + txt
        with open(dir_file, "w") as file:
            for line in gzipped_file:
                if "[CHAT]" in line:
                    file.write(line)
    

with open("C:\\Users\\[Your username here]\\mc_chat\\gz_names.txt", 'r') as file: #this will read the gz_names.txt file that's created by the c++ file
    for line in file:
        path = line[:-18]
        txt = line[-17:-1]
        print_file(path, txt)
