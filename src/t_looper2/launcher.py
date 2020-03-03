import subprocess

if __name__ == "__main__":
    nLoops = range(1, 5)
    nTasks = range(1, 7)
    for t in nTasks:
        for l in nLoops:
            subprocess.call(["bin/t_looper2", f"{l * 10 ** 7}", f"{t}", "2"])
