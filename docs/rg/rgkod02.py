# jeżeli jesteś w środku, broń się w miejscu
if self.location == rg.CENTER_POINT:
    return ['guard']

# jeżeli jesteś w środku, popełnij samobójstwo
if self.location == rg.CENTER_POINT:
    return ['suicide']
