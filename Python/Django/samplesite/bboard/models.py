from django.db import models

class Db(models.Model):
    """Data representation"""
    title = models.CharField(max_length=50)
    content = models.TextField(null=True, blank=True)
    price = models.FloatField(null=True, blank=True)
    published = models.DateTimeField(auto_now=True, db_index=True)
