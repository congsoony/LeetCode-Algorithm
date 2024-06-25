class ParkingSystem(object):

    def __init__(self, big, medium, small):
        self.cnt=[0]*4
        self.cnt[1]=big
        self.cnt[2]=medium
        self.cnt[3]=small
        

        

    def addCar(self, carType):
        if self.cnt[carType]==0:
            return False
        self.cnt[carType]-=1
        return True
        


# Your ParkingSystem object will be instantiated and called as such:
# obj = ParkingSystem(big, medium, small)
# param_1 = obj.addCar(carType)
