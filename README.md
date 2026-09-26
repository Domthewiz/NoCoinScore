# NoCoinScore

## Overview
This [RedCore](https://github.com/Zenith-Team/RedCore) module hides the score text when collecting coins in NSMBu.

## Setup Guide
### For Modders
- Download the **`bundle`** from the [latest release](https://github.com/Domthewiz/NoCoinScore/releases/latest) and extract it to your mod folder, merging the `code` folder into your project.
    - The `rules.txt` doesn't matter as long as the `version = 8` in your own.
- Running on console: Use the [Telkin](https://github.com/Zenith-Team/Telkin) aroma plugin to load your whole mod.
    - Place the `code` folders in `sd:/wiiu/telkin/TITLEID/` where `TITLEID` is the [title ID](https://wiiubrew.org/wiki/Title_database#00050000:_Game_Application_Titles) of your game's region (without dashes).
- Running on Cemu: Load and distribute your mod as a GraphicPack by placing it in Cemu's `graphicPacks` folder and activating it in the game's settings.

### Compiling
Install [Tachyon](https://github.com/Zenith-Team/Tachyon) (requires [Node.js](https://nodejs.org/) v24+)
```yml
npm i -g --allow-remote=root https://github.com/Zenith-Team/Tachyon/releases/latest/download/tachyon.tgz
```
Build and run the project for your region (example with `US`)
```rb
tachyon pm install
tachyon compile US
tachyon launch US
```
