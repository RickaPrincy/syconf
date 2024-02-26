# syconf

Sync rapidly your config to a github repository

### Usage

Create an env 'SYCONF_PATH' to tell syconf where your config is located.

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

### Commands

- syconf reload: check and copy new config for all paths given in the config file
- syconf commit: Commit new config (current_datetime as commit message)
- syconf stash: Stash the current uncommitted config
- syconf push: Push the newly committed config
