# Cuphead Gameboy Demake
Current project scope is just the first boss from cuphead - Root Pack

![Recording 2023-05-31 at 15 23 17](https://github.com/deluxturtle/cuphead_gb/assets/4693968/588d3c0b-fe59-46f7-bc98-ab25e9ef2ec5)

### Feature List
- [ ] Gameplay
    - [x] Jumping
    - [x] Simple Move
    - [ ] Platformer Bounds
    - [ ] Colliders
    - [x] Player Bullets
- [ ] Cuphead Animations
    - [x] Idle
    - [x] Standing Fire
    - [x] Normal Jump
    - [ ] Running Fire
- [ ] Potatoe Boss
    - [ ] Projectiles
    - [ ] Animations
    - [ ] Spawn / Death
- [ ] Flying Enemies
- [ ] Background Art

### Tools
GBDK-2020
Make
vscode
Emulicious

### Thanks For Help and GBDK2020
Toxa,
bbbbbr


### Learning Experiences

#### Big Animations For Boss
I had the idea of just using the background layer map to hold frames of animation for the boss and use the STAT Interupt scroll method/trick to slide the background to the frames for the animation.
I had to hide everything to the side of the boss because it would just be a whole sprite sheet across the screen but learned the Window causes all the background tiles to the right of it to stop being rendered so I had to flip where the boss was so it was to the left of the window.