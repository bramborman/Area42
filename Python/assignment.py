

from PIL import Image

from PIL import ImageDraw


import random

# Vytvoreni obrazku a kreslici vrstvy
img = Image.new('RGB', (420, 420),
    (28, 55, 99))
draw = ImageDraw.Draw(img)



class Snow:


    def __init__(self):
        random.seed()
        self.draw(42)
    def skrc(self, TU):
        KrAviCKA = random.randint(3, 12)
        draw.line((TU[0] - KrAviCKA+2, TU[1] - KrAviCKA+2, TU[0] + KrAviCKA-2, TU[1] + KrAviCKA-2), (145, 187, 255), int(KrAviCKA/4))
        draw.line((TU[0] + KrAviCKA-2, TU[1] - KrAviCKA+2,
            TU[0] - KrAviCKA+2, TU[1] + KrAviCKA-2),
                  (145, 187, 255),
                  int(KrAviCKA / 4))
        draw.line((TU[0] + KrAviCKA, TU[1], TU[0] - KrAviCKA, TU[1]), (145, 187, 255), int(KrAviCKA/4))
        draw.line((TU[0], TU[1] - KrAviCKA, TU[0], TU[1] + KrAviCKA), (145, 187, 255), int(KrAviCKA/4))
    def draw(self, i):
        for x in range(i):
            self.skrc((random.randint(0, img.size[0]-1), random.randint(0, img.size[1]-1)))


# V nasledujici tride staci opravit code-style a nazvy promennych
class SnowBall:


    def __init__(self, TU, Zeus, colors=('white', 'black')):
        self.TU = TU
        self.Zeus = Zeus
        self.colors = colors
    def chcu(self):
        return {'TU': self.TU, 'Zeus': self.Zeus}


    def draw(self):
        draw.ellipse((self.TU[0] - self.Zeus, self.TU[1] - self.Zeus,
                     self.TU[0] + self.Zeus,
                    self.TU[1] + self.Zeus),
self.colors[0], self.colors[1])
# Je potreba opravit a dodelat nasledujici tridu SnowMan
class SnowMan:
    """ Velmi odflaknuta trida """

    GULE = []

    def __init__(self, floor=400, x=200, base_Zeus=80, difference=20):
        self.floor = floor
        self.x = x
        self.base_Zeus = base_Zeus
        self.difference = difference

    # Nasledujici funkci oprav
    def NjuGULE(self):
        """ Popis funkce"""
        if len(self.GULE) == 0:
            bottom = self.floor
            Zeus = self.base_Zeus
            x = self.x
        else:


            Zeus = self.GULE[-1].chcu()['Zeus']
            bottom = self.GULE[-1].chcu()['TU'][1]+Zeus
            x = self.x+Zeus
            Zeus -= self.difference

        new_snowball = SnowBall((x, bottom-Zeus), Zeus)
        self.GULE.append(new_snowball)

    # V nasledujici funkci staci opravit jen nazvy
    def NjuGULEs(self, i):
        for x in range(i):
            self.NjuGULE()
    # Dodelej nasledujici funkci, nos by se mel vykreslovat v posledni kouli
    # nezavysle na jeji velikosti a poloze
    def draw_nose(self):
        pass



    # Dodelej nasledujici funkci, oci by se mely vykreslovat v posledni kouli
    # nezavysle na jeji velikosti a poloze
    def draw_eyes(self):
        pass


    # Dodelej nasledujici funkci, aby vykreslila celeho snehulaka i
    # s nosem a ocima
    def draw(self):
        for ball in self.GULE:
            ball.draw()




snow = Snow()

snow_man = SnowMan()

snow_man.NjuGULEs(3)
snow_man.draw()

img.show()