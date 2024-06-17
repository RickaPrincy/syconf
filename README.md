# syconf :zap:

Sync your config to a GitHub repository rapidly.

## Installation :seedling:

### Dependancies

- CMake (Version 3.15 or later)
- C++ Compiler with C++17 support

```bash
bash <(curl -s https://raw.githubusercontent.com/RickaPrincy/syconf/main/install.sh)
```
Or you can build it manually as usual for a CMake project

## Usage 

- Create a local repository to store your config and link it to a remote
- Configure all user commiter and user access for push for that repos
- Create directory and an `json file (syconf config)`, use the following example
- Create an environment variable named `SYCONF_PATH` to specify where your syconf config is stored.

#### Example of syconf config

```json
{
    "repository": "/home/user/repos_config",
    "configs": [
        {
            "input": "/home/user/.bashrc",
            "output": ""
        },
        {
            "input": "/home/user/.zshrc",
            "output": ""
        },
        {
            "input": "/home/user/.Xmodmap",
            "output": ""
        },
        {
            "input": "/home/user/.p10k.zsh",
            "output": ""
        },
        {
            "input": "/home/user/.profile",
            "output": ""
        },
        {
            "input": "/home/user/.config/lvim",
            "output": ".config/lvim"
        },
        {
            "input": "/home/user/.config/alacritty",
            "output": ".config/alacritty"
        },
        {
            "input": "/home/user/.config/syconf",
            "output": ".config/syconf"
        },
        {
            "input": "/home/user/.config/plank",
            "output": ".config/plank"
        },
        {
            "input": "/home/user/.config/plank",
            "output": ".config/plank"
        },
        {
            "input": "/home/user/.config/nvim",
            "output": ".config/nvim"
        }
    ]
}
```
Replace /path/to/your/config/repo with the actual path to your local repository and adjust the input and output paths according to your configuration files.

## Available Commands

- syconf reload: check and copy new config for all paths given in the config file
- syconf commit: Commit new config (current_datetime as commit message)
- syconf stash: Stash the current uncommitted config
- syconf push: Push the newly committed config
