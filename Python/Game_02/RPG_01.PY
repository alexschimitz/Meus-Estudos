from dataclasses import dataclass
import pygame
import os
from pathlib import Path

pygame.init()

# Obtém o diretório onde o script está localizado
script_dir = Path(__file__).parent

# Define o caminho para a pasta "sprites"
DIRETORIO_IMG = script_dir / "sprites"
# Define cores
WHITE = (255, 255, 255)
BLACK = (17, 17, 17)
 
# Define o comprimento e altura (WIDTH e HEIGHT) da tela (screen)
WIDTH = 792
HEIGHT = 521
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Collisions")
 
# Game Loop ficará ativo até que playing seja False
playing = True
# Define relógio e quadros por segundo
clock = pygame.time.Clock()
FPS = 60

# Carrega o fundo
background = pygame.image.load(f'{DIRETORIO_IMG}/background.png').convert_alpha()

# Carrega o sprite, transforma sua dimensão, obtém retângulo e define posição x e y
player_image = pygame.image.load(f'{DIRETORIO_IMG}/red.png').convert_alpha()
may_image = pygame.image.load(f'{DIRETORIO_IMG}/May.png').convert_alpha()


frame_width = 64   # Largura de cada frame
frame_height = 64  # Altura de cada frame
rows = 4  # Número de linhas
cols = 4  # Número de colunas

# Função para obter os frames individuais da sprite sheet
def get_frames(sprite_sheet, frame_width, frame_height, rows, cols):
    frames = []
    for row in range(rows):
        direction_frames = []
        for col in range(cols):
            frame = sprite_sheet.subsurface((col * frame_width, row * frame_height, frame_width, frame_height))
            direction_frames.append(frame)
        frames.append(direction_frames)  # Adiciona frames da direção
    return frames

# Obter os frames da sprite sheet
player_frames = get_frames(player_image, frame_width, frame_height, rows, cols)
may_frames = get_frames(may_image, frame_width, frame_height, rows, cols)
may_frame = may_frames[3][0]

# Índices para determinar o frame atual da animação
current_frame = 0
animation_speed = 5  # Controla a velocidade da animação

player_transformed = pygame.transform.scale(player_image, (50, 50))
player_rect = player_transformed.get_rect(topleft=(40, 150))  # Corrigido aqui
player_rect.x = 40
player_rect.y = 150
# Velocidade x e y do player
dx = 3.5
dy = 3.5

#   NPC - May

may_transformed = pygame.transform.scale(may_image, (125,150))
may_rect = may_transformed.get_rect()
may_rect.x = 380
may_rect.y = 340

portal_image = pygame.image.load(f'{DIRETORIO_IMG}/portal.png').convert_alpha()
portal_transformed = pygame.transform.scale(portal_image, (65,65))
portal_rect = portal_transformed.get_rect()
portal_rect.x = 655
portal_rect.y = 145

TV_image = pygame.image.load(f'{DIRETORIO_IMG}/TV.png')
TV_image.set_colorkey(WHITE)
TV_transformed = pygame.transform.scale(TV_image, (100,105))
TV_rect = TV_transformed.get_rect()
TV_rect.x = 355
TV_rect.y = 205

cama_image = pygame.image.load(f'{DIRETORIO_IMG}/cama.png').convert_alpha()
cama_transformed = pygame.transform.scale(cama_image, (100,180))
cama_rect = cama_transformed.get_rect()
cama_rect.x = 55
cama_rect.y = 275

skull_image = pygame.image.load(f'{DIRETORIO_IMG}/skull.png').convert_alpha()
skull_transformed = pygame.transform.scale(skull_image, (60,70))
skull_rect = skull_transformed.get_rect()
skull_rect.x = 285
skull_rect.y = 30

# Direção do personagem
moving_right = False 
moving_left = False
moving_top = False 
moving_down = False

# Movimento e colisões
@dataclass
class Movement:
    x: int 
    y: int

def collision_test(player, obstacles):
    collisions = []
    for obstacle in obstacles:
        if player.colliderect(obstacle):
            collisions.append(obstacle)
    return collisions

def move_and_collide(player, movement, obstacles):
    player.x += movement.x
    collisions_x = collision_test(player, obstacles)
    for obstacle in collisions_x:
        if movement.x > 0:
            player.right = obstacle.left
        if movement.x < 0:
            player.left = obstacle.right
        if obstacle.x == skull_rect.x:
            screen.fill(BLACK)
    player.y += movement.y
    collisions_y = collision_test(player, obstacles)
    for obstacle in collisions_y:
        if movement.y > 0:
            player.bottom = obstacle.top
        if movement.y < 0:
            player.top = obstacle.bottom
        if obstacle.y == skull_rect.y:
            screen.fill(BLACK)

# Defina uma variável para controlar a direção
current_direction = 0  # 0 = frente, 1 = esquerda, 2 = direita, 3 = trás
# Início do Game Loop
while playing:
    screen.blit(background, (0,0))

    movement = Movement(x=0, y=0)
    if moving_right:
        movement.x += dx
        current_direction = 2  # Direita
    if moving_left: 
        movement.x -= dx
        current_direction = 1  # Esquerda
    if moving_top:
        movement.y -= dy
        current_direction = 3 # Cima
    if moving_down: 
        movement.y += dy  
        current_direction = 0 # Baixo

    # Atualizar frame da animação apenas se o personagem estiver se movendo
    if moving_right or moving_left or moving_top or moving_down:
        current_frame = (current_frame + 1) % (len(player_frames[current_direction]) * animation_speed)
    frame = player_frames[current_direction][current_frame // animation_speed]

    if player_rect.x < 0:
        player_rect.x = 0
    elif player_rect.x + player_transformed.get_width() > WIDTH:
        player_rect.x = WIDTH - player_transformed.get_width()
    if player_rect.y < 0:
        player_rect.y = 0
    elif player_rect.y + player_transformed.get_height() > HEIGHT:
        player_rect.y = HEIGHT - player_transformed.get_height()

    if player_rect.colliderect(portal_rect):
        player_rect.x = 430
        player_rect.y = 310

    obstacles = [TV_rect, cama_rect, skull_rect, may_rect]
    move_and_collide(player_rect, movement, obstacles)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            playing = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_RIGHT:
                moving_right = True 
            if event.key == pygame.K_LEFT:
                moving_left = True 
            if event.key == pygame.K_UP:
                moving_top = True
            if event.key == pygame.K_DOWN:
                moving_down = True
        if event.type == pygame.KEYUP:
            if event.key == pygame.K_RIGHT:
                moving_right = False 
            if event.key == pygame.K_LEFT:
                moving_left = False
            if event.key == pygame.K_UP:
                moving_top = False
            if event.key == pygame.K_DOWN:
                moving_down = False

    screen.blit(frame, [player_rect.x, player_rect.y])
    screen.blit(portal_transformed, [portal_rect.x, portal_rect.y])
    screen.blit(TV_transformed, [TV_rect.x, TV_rect.y])
    screen.blit(cama_transformed, [cama_rect.x, cama_rect.y])
    screen.blit(skull_transformed, [skull_rect.x, skull_rect.y])
    screen.blit(may_frame, [may_rect.x, may_rect.y])

    pygame.display.update()
    clock.tick(FPS)

pygame.quit()