import random
from PIL import Image
from PIL import ImageDraw


# Vytvoreni obrazku a kreslici vrstvy
img = Image.new("RGB", (420, 420), (28, 55, 99))
draw = ImageDraw.Draw(img)


class Snow:

    __random_initialized = False

    def __init__(self, colors=("white", "black", (145, 187, 255))):
        if not self.__random_initialized:
            random.seed()
            self.__random_initialized = True
        
        self.__colors = colors

    @property
    def fill(self):
        return self.__colors[0]

    @property
    def outline(self):
        return self.__colors[1]

    @property
    def snowflake_color(self):
        return self.__colors[2]

    def __add_snowflake(self, center):
        size = random.randint(3, 12)
        width = int(size / 4)
        x, y = center

        draw.line((x - size + 2, y - size + 2, x + size - 2, y + size - 2),
                  self.__colors[2], width)  # /
        draw.line((x + size - 2, y - size + 2, x - size + 2, y + size - 2),
                  self.__colors[2], width)  # \
        draw.line((x + size, y, x - size, y),
                  self.__colors[2], width)  # -
        draw.line((x, y - size, x, y + size),
                  self.__colors[2], width)  # |

    def __add_snowdrift(self):
        ellipse_height = img.size[1] * 0.1
        img_right = img.size[0] - 1
        img_bottom = img.size[1] - 1

        draw.ellipse((-30, img_bottom - ellipse_height, img_right + 30, img_bottom + ellipse_height), self.__colors[0], self.__colors[1])

    def draw(self, snowflakes_count=42):
        for x in range(snowflakes_count):
            x = random.randint(0, img.size[0] - 1)
            y = random.randint(0, img.size[1] - 1)

            self.__add_snowflake((x, y))
        
        self.__add_snowdrift()


class SnowBall:
    def __init__(self, center, radius, colors):
        self.__center = center
        self.__radius = radius
        self.__colors = colors
    
    @property
    def center(self):
        return self.__center

    @property
    def radius(self):
        return self.__radius

    @property
    def fill(self):
        return self.__colors[0]

    @property
    def outline(self):
        return self.__colors[1]

    def draw(self):
        draw.ellipse((self.__center[0] - self.__radius, self.__center[1] - self.__radius,
                     self.__center[0] + self.__radius, self.__center[1] + self.__radius),
                     self.__colors[0], self.__colors[1])


class SnowMan:
    def __init__(self, floor=400, x=200, base_radius=80, difference=20, colors=("white", "black", "orange", "red")):
        self.__floor = floor
        self.__x = x
        self.__base_radius = base_radius
        self.__difference = difference
        self.__colors = colors

        self.__balls = []
    
    @property
    def floor(self):
        return self.__floor
    
    @property
    def x(self):
        return self.__x
    
    @property
    def base_radius(self):
        return self.__base_radius
    
    @property
    def difference(self):
        return self.__difference

    @property
    def fill(self):
        return self.__colors[0]

    @property
    def outline(self):
        return self.__colors[1]

    @property
    def nose_color(self):
        return self.__colors[2]

    @property
    def hat_color(self):
        return self.__colors[3]

    def add_ball(self):
        if len(self.__balls) == 0:
            bottom = self.__floor
            radius = self.__base_radius
        else:
            radius = self.__balls[-1].radius
            # Thanks to (radius // 3) the snow balls overlap each other
            # so the image looks better IMHO
            bottom = self.__balls[-1].center[1] - radius + (radius // 3)
            radius -= self.__difference

        new_snowball = SnowBall((self.__x, bottom - radius), radius, self.__colors[:2])
        self.__balls.append(new_snowball)

    def add_balls(self, count):
        for x in range(count):
            self.add_ball()

    def __draw_eyes(self):
        radius = self.__balls[-1].radius
        x, y = self.__balls[-1].center
        offset = radius // 3
        size = (radius // 10, radius // 5)

        x -= offset
        y -= offset

        draw.ellipse((x - size[0], y - size[1], x + size[0], y + size[1]), self.__colors[1], self.__colors[1])

        x += 2 * offset

        draw.ellipse((x - size[0], y - size[1], x + size[0], y + size[1]), self.__colors[1], self.__colors[1])   

    def __draw_nose(self):
        radius = self.__balls[-1].radius
        x, y = self.__balls[-1].center
        offset = (radius // 2, radius // 4)

        draw.polygon((x, y, x - offset[0], y + (1.5 * offset[1]), x, y + (1.2 * offset[1])), self.__colors[2], self.__colors[2])

    def __draw_hands(self):
        index = -1 if len(self.__balls) == 1 else -2
        radius = self.__balls[index].radius
        x, y = self.__balls[index].center
        new_radius = radius // 3

        draw.ellipse((x - radius - (2 * new_radius), y - new_radius, x - radius, y + new_radius), self.__colors[0], self.__colors[1])
        draw.ellipse((x + radius, y - new_radius, x + radius + (2 * new_radius), y + new_radius), self.__colors[0], self.__colors[1])

    def __draw_hat(self):
        radius = self.__balls[-1].radius
        x, y = self.__balls[-1].center
        size = (radius - (radius // 10), radius // 2)
        size_bottom = (radius + (radius // 10), radius // 10)

        draw.rectangle((x - size[0], y - radius - size[1], x + size[0], y - size[1]), self.__colors[3], self.__colors[1])
        draw.rectangle((x - size_bottom[0], y - size[1] - size_bottom[1], x + size_bottom[0], y - size[1]), self.__colors[3], self.__colors[1])

    def draw(self):
        for ball in self.__balls:
            ball.draw()
        
        self.__draw_eyes()
        self.__draw_nose()
        self.__draw_hands()
        self.__draw_hat()


Snow().draw()
snow_man = SnowMan()

snow_man.add_balls(3)
snow_man.draw()

img.show()
