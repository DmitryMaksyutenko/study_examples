# Generated by Django 2.2.4 on 2019-09-17 12:38

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('bboard', '0001_initial'),
    ]

    operations = [
        migrations.CreateModel(
            name='Rubric',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(db_index=True, max_length=20, verbose_name='Название')),
            ],
            options={
                'verbose_name': 'Рубрика',
                'verbose_name_plural': 'Рубрики',
                'ordering': ['name'],
            },
        ),
        migrations.AlterModelOptions(
            name='db',
            options={'ordering': ['-published'], 'verbose_name': 'Объявление', 'verbose_name_plural': 'Объявления'},
        ),
        migrations.AlterField(
            model_name='db',
            name='content',
            field=models.TextField(blank=True, null=True, verbose_name='Описание'),
        ),
        migrations.AlterField(
            model_name='db',
            name='price',
            field=models.FloatField(blank=True, null=True, verbose_name='Цена'),
        ),
        migrations.AlterField(
            model_name='db',
            name='published',
            field=models.DateTimeField(auto_now=True, db_index=True, verbose_name='Опублтковано'),
        ),
        migrations.AlterField(
            model_name='db',
            name='title',
            field=models.CharField(max_length=50, verbose_name='Товар'),
        ),
        migrations.AddField(
            model_name='db',
            name='rubric',
            field=models.ForeignKey(null=True, on_delete=django.db.models.deletion.PROTECT, to='bboard.Rubric', verbose_name='Рубрика'),
        ),
    ]
